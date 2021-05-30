from django.shortcuts import render
from django.http import HttpResponse

from . import forms
# Create your views here.


def index(request):

    context = {}
    context['personForm'] = forms.PersonForm()
    context['livesForm'] = forms.LivesForm()
    context['worksForm'] = forms.WorksForm()

    return render(request, "templates/index2.html", context)
    # return HttpResponse("Hi there")


def success_view(request):

    personForm = forms.PersonForm()
    worksForm = forms.WorksForm()
    livesForm = forms.LivesForm()

    if request.method == "POST":

        personForm = forms.PersonForm(request.POST)

        if personForm.is_valid():

            personForm_name = personForm.cleaned_data["name"]

            personForm_street = personForm.cleaned_data["street"]
            personForm_city = personForm.cleaned_data["city"]
            
            personForm_company = personForm.cleaned_data["company"]
            personForm_salary = personForm.cleaned_data["salary"]

            print("inserted ==>", personForm_name, personForm_street, personForm_city,
                  personForm_company, personForm_salary)

            

    return render(request, "templates/success2.html", context=None)
