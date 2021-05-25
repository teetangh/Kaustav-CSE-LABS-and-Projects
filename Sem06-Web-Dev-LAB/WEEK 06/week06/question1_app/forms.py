# import the standard Django Forms
# from built-in library
from django import forms
from django.forms.widgets import TextInput

from django.db import models


class InputForm(forms.Form):
    first_name = forms.CharField(max_length=200, widget=TextInput(
        attrs={
            'class': 'form-control',
            "placeholder": "first_name",
            "background-color": "blue"
        }))

    last_name = forms.CharField(max_length=200, widget=TextInput(
        attrs={
            'class': 'form-control',
            "placeholder": "last_name",
            "background-color": "blue"}))
    roll_number = forms.IntegerField(
        help_text="Enter 6 digit roll number", widget=TextInput(
            attrs={'class': 'form-control',
                   "placeholder": "roll_number",
                   "background-color": "blue"}))
    password = forms.CharField(widget=forms.PasswordInput(
        attrs={
            'class': 'form-control',
            "placeholder": "password",
            "background-color": "blue"}))


class CarForm(forms.Form):
    car_name = forms.CharField(max_length=200, widget=TextInput(
        attrs={
            'class': 'form-control ',
            "placeholder": "car_name",
            "background-color": "blue"
        }))
