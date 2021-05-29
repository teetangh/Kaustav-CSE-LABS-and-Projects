# import the standard Django Forms
# from built-in library
from django import forms
from django.forms.widgets import TextInput

from . import models


class CategoryForm(forms.ModelForm):

    class Meta:
        model = models.Category
        fields = "__all__"


class PageForm(forms.ModelForm):

    class Meta:
        model = models.Page
        fields = "__all__"
