from django.contrib.auth import authenticate, login, logout
from django.db import IntegrityError
from django.http import HttpResponse, JsonResponse, HttpResponseRedirect
from django.shortcuts import render
from django.urls import reverse
from django.views.decorators.http import require_http_methods

from .models import User, Post
from datetime import datetime
from django.contrib.auth.decorators import login_required
from django.core.paginator import Paginator


def index(request):
    posts = Post.objects.all()
    posts = list(reversed(posts))
    paginator = Paginator(posts, 10)

    page_number = request.GET.get('page')
    page_obj = paginator.get_page(page_number)

    range = paginator.page_range
    iterator = ""
    for i in range:
        iterator += f"{i}"

    return render(request, "network/index.html", {'page_obj': page_obj, 'iterator': iterator})


@require_http_methods(["POST"])
def createPosts(request):

    Post.objects.create(
        username = request.user,
        content = request.POST["content"],
    )

    return HttpResponseRedirect(reverse('index'))


def user(request, username):
    selected_user = User.objects.get(username=username)

    posts = list(reversed(selected_user.posts.all()))
    paginator = Paginator(posts, 10)

    page_number = request.GET.get('page')
    page_obj = paginator.get_page(page_number)

    range = paginator.page_range
    iterator = ""
    for i in range:
        iterator += f"{i}"

    return render(request, "network/user.html", {'selected_user': selected_user, 'page_obj': page_obj, 'iterator': iterator})


@login_required(login_url='login')
def like(request, post_id):
    post = Post.objects.get(pk=post_id)
    if request.user in post.likes.all():
        post.likes.remove(request.user)
        response = '<svg width="1em" height="1em" viewBox="0 0 16 16" class="bi bi-heart" fill="red" xmlns="http://www.w3.org/2000/svg"><path fill-rule="evenodd" d="M8 2.748l-.717-.737C5.6.281 2.514.878 1.4 3.053c-.523 1.023-.641 2.5.314 4.385.92 1.815 2.834 3.989 6.286 6.357 3.452-2.368 5.365-4.542 6.286-6.357.955-1.886.838-3.362.314-4.385C13.486.878 10.4.28 8.717 2.01L8 2.748zM8 15C-7.333 4.868 3.279-3.04 7.824 1.143c.06.055.119.112.176.171a3.12 3.12 0 0 1 .176-.17C12.72-3.042 23.333 4.867 8 15z"/></svg>'
    else:
        post.likes.add(request.user)
        response = '<svg width="1em" height="1em" viewBox="0 0 16 16" class="bi bi-heart-fill" fill="red" xmlns="http://www.w3.org/2000/svg"><path fill-rule="evenodd" d="M8 1.314C12.438-3.248 23.534 4.735 8 15-7.534 4.736 3.562-3.248 8 1.314z"/></svg>'
    likes = post.likes.count()
    result = {
        'html': response,
        'likes': likes
    }
    return JsonResponse({'result': result})


def follow(request, user_id):
    user2follow = User.objects.get(pk=user_id)

    if request.user in user2follow.followers.all():
        user2follow.followers.remove(request.user)
        button = "Follow"
    else:
        user2follow.followers.add(request.user)
        button = "Unfollow"

    result = {
        'button': button,
        'following': user2follow.following.count(),
        'followers': user2follow.followers.count()
    }

    return JsonResponse({'result': result})


def posts_following(request):
    posts = []
    for followed in request.user.following.all():
        for post in followed.posts.all():
            posts.append(post)

    posts = list(reversed(posts))
    paginator = Paginator(posts, 10)

    page_number = request.GET.get('page')
    page_obj = paginator.get_page(page_number)

    range = paginator.page_range
    iterator = ""
    for i in range:
        iterator += f"{i}"

    return render(request, "network/layout.html", {'page_obj': page_obj, 'iterator': iterator})


def edit(request, post_id):

    post = Post.objects.get(pk=post_id)

    if request.method == 'POST':
        post.content = request.POST['content']
        post.save()

        return HttpResponseRedirect(reverse('index'))

    return render(request, "network/edit.html", {'post': post})


def login_view(request):
    if request.method == "POST":

        # Attempt to sign user in
        username = request.POST["username"]
        password = request.POST["password"]
        user = authenticate(request, username=username, password=password)

        # Check if authentication successful
        if user is not None:
            login(request, user)
            return HttpResponseRedirect(reverse("index"))
        else:
            return render(request, "network/login.html", {
                "message": "Invalid username and/or password."
            })
    else:
        return render(request, "network/login.html")


def logout_view(request):
    logout(request)
    return HttpResponseRedirect(reverse("index"))


def register(request):
    if request.method == "POST":
        username = request.POST["username"]
        email = request.POST["email"]

        # Ensure password matches confirmation
        password = request.POST["password"]
        confirmation = request.POST["confirmation"]
        if password != confirmation:
            return render(request, "network/register.html", {
                "message": "Passwords must match."
            })

        # Attempt to create new user
        try:
            user = User.objects.create_user(username, email, password)
            user.save()
        except IntegrityError:
            return render(request, "network/register.html", {
                "message": "Username already taken."
            })
        login(request, user)
        return HttpResponseRedirect(reverse("index"))
    else:
        return render(request, "network/register.html")
