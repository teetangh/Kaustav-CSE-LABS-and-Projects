from django.shortcuts import render
from . import forms
from . import models

# Create your views here.


def index(request):

    context = {}
    context["categoryForm"] = forms.CategoryForm()
    context["pageForm"] = forms.PageForm()

    return render(request, "templates/index.html", context)


def success_view(request):

    categoryForm = forms.CategoryForm()
    pageForm = forms.PageForm()

    if request.method == "POST":

        categoryForm = forms.CategoryForm(request.POST)
        pageForm = forms.PageForm(request.POST)

        if categoryForm.is_valid():
            categoryForm_name = categoryForm.cleaned_data["name"]
            categoryForm_email = categoryForm.cleaned_data["email"]
            categoryForm_visits = categoryForm.cleaned_data["visits"]
            categoryForm_likes = categoryForm.cleaned_data["likes"]

            print("DEBUG 1 ",
                  categoryForm_name,
                  categoryForm_email,
                  categoryForm_visits,
                  categoryForm_likes)

        if pageForm.is_valid():
            pageForm_category = pageForm.cleaned_data["category"]
            pageForm_title = pageForm.cleaned_data["title"]
            pageForm_url = pageForm.cleaned_data["url"]
            pageForm_views = pageForm.cleaned_data["views"]

            print("DEBUG 2",
                  pageForm_category,
                  pageForm_title,
                  pageForm_url,
                  pageForm_views)

    return render(request, "templates/success.html", context=None)
