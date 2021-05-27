from .forms import CarForm, InputForm
from django.shortcuts import render
from . import forms
from . import models


from .models import CarModel
# Create your views here.


def index(request):
    results = CarModel.objects.all

    inputForm = {}
    inputForm['form'] = InputForm()

    carForm = {}
    carForm['form'] = CarForm()

    return render(request, "templates/index.html", {"showManufacturer": results, "inputForm": inputForm, "carForm": carForm})


def success_view(request):
    inputForm = forms.InputForm()
    carForm = forms.CarForm()

    if request.method == 'POST':

        inputForm = forms.InputForm(request.POST)
        carForm = forms.CarForm(request.POST)

        if inputForm.is_valid():

            first_name = inputForm.cleaned_data['first_name']
            last_name = inputForm.cleaned_data['last_name']
            roll_number = inputForm.cleaned_data['roll_number']
            password = inputForm.cleaned_data['password']

            print("DEBUG 1",
                  first_name,
                  last_name,
                  roll_number,
                  password)

        if carForm.is_valid():
            car_name = carForm.cleaned_data['car_name']
            car_brand = carForm.cleaned_data["car_brand"]
            # car_brand = dict(carForm.fields['car_brand'].choices)[car_brand]

            print("DEBUG 2",
                  car_name, car_brand)

    return render(request, "templates/success.html", context=None)
