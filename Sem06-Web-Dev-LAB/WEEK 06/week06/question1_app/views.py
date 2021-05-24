from django.forms.utils import pretty_name
from .forms import InputForm
from django.shortcuts import render
from django.http import HttpResponse
from . import forms
# Create your views here.


def index(request):
    context = {}
    context['form'] = InputForm()
    return render(request, "templates/index.html", context)


# Create your views here.


# def home_view(request):
#     context = {}
#     context['form'] = InputForm()
#     return render(request, "templates/success.html", context)


def success_view(request):
    form = forms.InputForm()
    print("debug 1")
    if request.method == 'POST':
        print("debug 2")

        form = forms.InputForm(request.POST)
        if form.is_valid():
            print("debug 3")

            first_name = form.cleaned_data['first_name']
            last_name = form.cleaned_data['last_name']
            roll_number = form.cleaned_data['roll_number']
            password = form.cleaned_data['password']

            print(first_name,
                  last_name,
                  roll_number,
                  password)
    return render(request, "templates/success.html", context=None)
