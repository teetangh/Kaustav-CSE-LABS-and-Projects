from django import forms


class CustomerForm(forms.Form):
    username = forms.CharField(max_length=200)
    # password = forms.PasswordField(max_length=100)
    password = forms.CharField(widget=forms.PasswordInput())

    email = forms.EmailField(max_length=100, required=False)
    contact = forms.IntegerField(max_value=9999999999)
