from .forms import InputForm
from django.shortcuts import render
from . import forms


from .models import CarModel
# Create your views here.


def index(request):
    context = {}
    context['form'] = InputForm()
    return render(request, "templates/index.html", context)


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


def showlist(request):

    context = {}
    context['form'] = InputForm()
    results = CarModel.objects.all
    return render(request, "templates/list.html", {"showcity": results, "context": context})
