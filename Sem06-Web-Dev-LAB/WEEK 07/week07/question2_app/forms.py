from django import forms
from . import models


class PersonForm(forms.ModelForm):

    class Meta:
        model = models.PersonModel
        fields = "__all__"


class WorksForm(forms.ModelForm):

    class Meta:
        model = models.WorksModel
        fields = "__all__"


class LivesForm(forms.ModelForm):

    class Meta:
        model = models.LivesModel
        fields = "__all__"
