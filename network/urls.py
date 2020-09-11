
from django.urls import path

from . import views

urlpatterns = [
    path("", views.index, name="index"),
    path("login", views.login_view, name="login"),
    path("logout", views.logout_view, name="logout"),
    path("register", views.register, name="register"),
    path("posts_following", views.posts_following, name="posts_following"),
    path("createPosts", views.createPosts, name="createPosts"),
    path("like/<int:post_id>", views.like, name="like"),
    path("<str:username>", views.user, name="user"),
    path("follow/<int:user_id>", views.follow, name="follow"),
    path("edit/<int:post_id>", views.edit, name="edit")
]
