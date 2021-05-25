from django.db import models


class CarModel(models.Model):
    manufacturer_name = models.CharField(max_length=30)

    def __name__(self):
        return self.manufacturer_name

    class Meta:
        db_table = "question1_app_car"

