# Generated by Django 3.2.3 on 2021-05-24 18:22

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='CarModel',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('manufacturer_name', models.CharField(max_length=30)),
            ],
            options={
                'db_table': 'question1_app_car',
            },
        ),
    ]