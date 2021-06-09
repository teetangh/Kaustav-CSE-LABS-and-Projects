
from django import forms

from . import models


class StudentModelForm(forms.ModelForm):

    class Meta:
        model = models.StudentModel
        fields = "__all__"
