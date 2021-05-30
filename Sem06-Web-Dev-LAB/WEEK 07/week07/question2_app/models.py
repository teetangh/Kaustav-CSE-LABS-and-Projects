from django.db import models

# Create your models here.


class WorksModel(models.Model):
    company = models.CharField(max_length=200)
    salary = models.IntegerField()


class LivesModel(models.Model):
    street = models.CharField(max_length=300)
    city = models.CharField(max_length=300)


class PersonModel(models.Model):
    name = models.CharField(max_length=200, primary_key=True)

    company = models.ForeignKey(WorksModel, on_delete=models.CASCADE)

    street = models.ForeignKey(
        LivesModel, related_name="preson_city",  max_length=300, on_delete=models.CASCADE)
    city = models.ForeignKey(
        LivesModel, related_name="person_street",  max_length=300, on_delete=models.CASCADE)

    def __str__(self):
        return self.name
