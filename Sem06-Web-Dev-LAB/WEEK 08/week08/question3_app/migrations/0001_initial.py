# Generated by Django 3.0.5 on 2021-05-30 19:59

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='RomatoRestaurantModel',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('name', models.CharField(max_length=255)),
                ('cuisine', models.CharField(max_length=255)),
                ('location', models.CharField(max_length=255)),
            ],
        ),
    ]
