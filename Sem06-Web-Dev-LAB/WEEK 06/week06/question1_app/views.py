from .forms import CarForm, InputForm
from django.shortcuts import render
from . import forms
from . import models


from .models import CarModel
# Create your views here.


def index(request):
    results = CarModel.objects.all

    inputContext = {}
    inputContext['form'] = InputForm()

    carContext = {}
    carContext['form'] = CarForm()

    return render(request, "templates/index.html", {"showManufacturer": results, "inputContext": inputContext, "carContext": carContext})


def success_view(request):
    form = forms.InputForm()
    if request.method == 'POST':

        form = forms.InputForm(request.POST)
        if form.is_valid():

            first_name = form.cleaned_data['first_name']
            last_name = form.cleaned_data['last_name']
            roll_number = form.cleaned_data['roll_number']
            password = form.cleaned_data['password']

            print(first_name,
                  last_name,
                  roll_number,
                  password)
    return render(request, "templates/success.html", context=None)
