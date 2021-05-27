from django import forms


class ProductForm(forms.Form):

    COMPANIES = ["HP", "Nokia", "Samsung", "Motorola", "Apple"]
    COMPANIES_CHOICES = [(item.lower(), item.upper()) for item in COMPANIES]

    DEVICES = ["Mobile", "Laptop"]
    DEVICES_CHOICES = [(item.lower(), item.upper()) for item in DEVICES]

    company = forms.ChoiceField(
        choices=COMPANIES_CHOICES, widget=forms.RadioSelect)

    device = forms.MultipleChoiceField(
        required=False,
        widget=forms.CheckboxSelectMultiple,
        choices=DEVICES_CHOICES,
    )
