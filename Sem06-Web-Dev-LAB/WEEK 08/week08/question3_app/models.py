from django.db import models


class RomatoRestaurantModel(models.Model):
    name = models.CharField(max_length=255)
    cuisine = models.CharField(max_length=255)
    location = models.CharField(max_length=255)

    def __str__(self):
        return '{},{},{}'.format(self.name, self.cuisine, self.location)
