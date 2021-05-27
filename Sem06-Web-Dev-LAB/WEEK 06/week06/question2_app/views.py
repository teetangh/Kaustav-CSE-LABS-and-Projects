from django.shortcuts import render
from django.http import HttpResponse
from . import forms

# Create your views here.


def firstPage(request):
    # return HttpResponse("Hi there")

    context = {}
    context["student_form"] = forms.StudentForm()

    return render(request, "templates/firstPage.html", context)


def secondPage(request):
    # return HttpResponse("HI there")

    student_form = forms.StudentForm()

    context = {}
    if request.method == "POST":
        student_form = forms.StudentForm(request.POST)

        if student_form.is_valid():
            student_name = student_form.cleaned_data["name"]
            student_roll_number = student_form.cleaned_data["roll_number"]
            student_birth_year = student_form.cleaned_data["birth_year"]
            student_subject = student_form.cleaned_data["subject"]

            print(student_name,
                  student_roll_number,
                  student_birth_year,
                  student_subject)

            context["student_name"] = student_name
            context["student_roll_number"] = student_roll_number
            context["student_birth_year"] = student_birth_year
            context["student_subject"] = student_subject

    return render(request, "templates/secondPage.html", context)
