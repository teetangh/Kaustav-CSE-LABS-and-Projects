# Generated by Django 3.0.5 on 2021-05-30 19:12

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('question2_app', '0002_remove_olaridemodel_eta'),
    ]

    operations = [
        migrations.AddField(
            model_name='olaridemodel',
            name='eta',
            field=models.DurationField(null=True),
        ),
    ]
