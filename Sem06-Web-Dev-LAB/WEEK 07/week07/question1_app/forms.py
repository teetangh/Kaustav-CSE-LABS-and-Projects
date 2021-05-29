# import the standard Django Forms
# from built-in library
from django import forms
from django.forms.widgets import TextInput

from . import models


class CategoryModelForm(forms.ModelForm):

    class Meta:
        model = models.CategoryModel
        fields = "__all__"


class PageModelForm(forms.ModelForm):

    class Meta:
        model = models.PageModel
        fields = "__all__"
