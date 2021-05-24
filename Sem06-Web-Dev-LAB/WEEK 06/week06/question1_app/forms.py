# import the standard Django Forms
# from built-in library
from django import forms
from django.forms.widgets import TextInput

from django.db import models


class InputForm(forms.Form):
    first_name = forms.CharField(max_length=200, widget=TextInput(
        attrs={'class': 'form-control', 'id': 'kaustav'}))
    last_name = forms.CharField(max_length=200)
    roll_number = forms.IntegerField(
        help_text="Enter 6 digit roll number"
    )
    password = forms.CharField(widget=forms.PasswordInput())
