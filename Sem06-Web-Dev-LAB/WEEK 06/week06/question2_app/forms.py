from django import forms

BIRTH_YEAR_CHOICES = [str(date) for date in range(2021, 1799, -1)]

SUBJECTS_CHOICES = [
    ('physics', 'Physics'),
    ('chemistry', 'Chemistry'),
    ('biology', 'Biology'),
]

ROLL_NUMBER_CHOICES = [str(roll) for roll in range(0, 101, 1)]


class StudentForm(forms.Form):
    birth_year = forms.DateField(
        widget=forms.SelectDateWidget(years=BIRTH_YEAR_CHOICES))

    # subject = forms.MultipleChoiceField(
    #     required=False,
    #     widget=forms.CheckboxSelectMultiple,
    #     choices=SUBJECTS_CHOICES,
    # )

    subject = forms.ChoiceField(
        required=False,
        choices=SUBJECTS_CHOICES,
    )

    roll_number = forms.IntegerField(min_value=0, max_value=100)
    name = forms.CharField(min_length=3, max_length=100)
