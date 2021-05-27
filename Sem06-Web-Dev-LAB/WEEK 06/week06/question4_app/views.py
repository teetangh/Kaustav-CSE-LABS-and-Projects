from django.shortcuts import render
from django.http import HttpResponse

from .forms import ProductForm

# Create your views here.


def register(request):

    context = {}
    context["product_form"] = ProductForm()

    return render(request, "templates/registerPage.html", context)


def success(request):
    return HttpResponse("Hi there Success")
