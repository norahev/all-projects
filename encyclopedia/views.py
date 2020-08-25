import random

from django import forms
from django.http import HttpResponseRedirect
from django.shortcuts import render
from django.urls import reverse

from . import util

from markdown2 import Markdown

markdown = Markdown()


class Search(forms.Form):
    item = forms.CharField()

class Post(forms.Form):
    title = forms.CharField(label= "Title")
    textarea = forms.CharField(widget=forms.Textarea(), label='')

class Edit(forms.Form):
    textarea = forms.CharField(widget=forms.Textarea(), label='')

def index(request):
    entries = util.list_entries()
    searched = []
    if request.method == "POST":
        form = Search(request.POST)
        if form.is_valid():
            item = form.cleaned_data["item"]
            for i in entries:
                if item in entries:
                    page = util.get_entry(item)
                    convertedpage = markdown.convert(page)
                    return render(request, "encyclopedia/entry.html", {"page": convertedpage, "title": item, "form":Search()})
                if item.lower() in i.lower(): 
                    searched.append(i)
            return render(request, "encyclopedia/search.html", {"searched": searched, "form":Search()})

        else:
            return render(request, "encyclopedia/index.html", {"form": form})
    else:
        return render(request, "encyclopedia/index.html", {
            "entries": util.list_entries(), "form":Search()
        })

def entry(request, title):
    entries = util.list_entries()
    if title in entries:
        page = util.get_entry(title)
        convertedpage = markdown.convert(page)
        return render(request, "encyclopedia/entry.html", {"page": convertedpage, "title": title, "form":Search()})
    else:
        return render(request, "encyclopedia/error.html", {"errormessage": "The requested page was not found.", "form":Search()})


def create(request):
    if request.method == 'POST':
        form = Post(request.POST)
        if form.is_valid():
            title = form.cleaned_data["title"]
            textarea = form.cleaned_data["textarea"]
            entries = util.list_entries()
            if title in entries:
                return render(request, "encyclopedia/error.html", {"form": Search(), "errormessage": "Page already exist"})
            else:
                util.save_entry(title,textarea)
                page = util.get_entry(title)
                convertedpage = markdown.convert(page)
                return render(request, "encyclopedia/entry.html", {"form": Search(), "page": convertedpage, "title": title})
    else:
        return render(request, "encyclopedia/create.html", {"form": Search(), "post": Post()})


def edit(request, title):
    if request.method == 'GET':
        page = util.get_entry(title)
        return render(request, "encyclopedia/edit.html", {"form": Search(), "edit":Edit(initial={'textarea': page}), 'title':title})
    else:
        form = Edit(request.POST) 
        if form.is_valid():
            textarea = form.cleaned_data["textarea"]
            util.save_entry(title,textarea)
            page = util.get_entry(title)
            convertedpage = markdown.convert(page)
            return render(request, "encyclopedia/entry.html", {"form": Search(), "page": convertedpage, "title": title})

def randompage(request):
    if request.method == 'GET':
        entries = util.list_entries()
        nr = random.randint(0, len(entries) - 1)
        randompage = entries[nr]
        page = util.get_entry(randompage)
        convertedpage = markdown.convert(page)

        return render(request, "encyclopedia/entry.html", {"form": Search(), "page": convertedpage, "title": randompage})

