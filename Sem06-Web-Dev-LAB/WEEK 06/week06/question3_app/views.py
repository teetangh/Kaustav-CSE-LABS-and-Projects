from django.shortcuts import render
from django.http import HttpResponse

from .forms import CustomerForm

# Create your views here.


def register(request):
    context = {}
    context["customer"] = CustomerForm()

    return render(request, "templates/registerPage.html", context)


def success(request):
    # return HttpResponse("Hi there")

    customer_form = CustomerForm()

    context = {}
    if request.method == "POST":

        customer_form = CustomerForm(request.POST)

        if customer_form.is_valid():

            customer_username = customer_form.cleaned_data["username"]
            customer_password = customer_form.cleaned_data["password"]
            customer_email = customer_form.cleaned_data["email"]
            customer_contact = customer_form.cleaned_data["contact"]

            print(customer_username,
                  customer_password,
                  customer_email,
                  customer_contact)

            context["customer_username"] = customer_username
            context["customer_password"] = customer_password
            context["customer_email"] = customer_email
            context["customer_contact"] = customer_contact

    return render(request, "templates/successsPage.html", context)
