
from django.shortcuts import render
from . import forms
from . import models

# Create your views here.


def index(request):

    context = {}
    context["studentForm"] = forms.StudentModelForm()

    if request.method == "POST":

        studentForm = forms.StudentModelForm(request.POST)

        if studentForm.is_valid():
            studentForm_name = studentForm.cleaned_data["name"]
            studentForm_regno = studentForm.cleaned_data["regno"]
            studentForm_cgpa = studentForm.cleaned_data["cgpa"]

            print("inserted student ===> ", studentForm_name,
                  studentForm_regno, studentForm_cgpa)

            student_db = models.StudentModel(
                name=studentForm_name,
                regno=studentForm_regno,
                cgpa=studentForm_cgpa,
            )
            student_db.save()

    return render(request, "templates/index.html", context)


def success_view(request):

    studentForm = forms.StudentModelForm()

    context = {}

    context["studentModelQueries"] = models.StudentModel.objects.all()

    return render(request, "templates/success.html", context=context)


def filter(request):

    studentForm = forms.StudentModelForm()
    context = {}
    print("Hi")

    if request.method == 'POST':
        studentForm = forms.StudentModelForm(request.POST)

        if studentForm.is_valid():
            reg_no = studentForm.cleaned_data['Search']
            reg_no=int(reg_no)
            print(reg_no)
            context["studentModelQueries"] = models.StudentModel.objects.filter(
                regno=reg_no)

    return render(request, "templates/filter.html", context=context)
