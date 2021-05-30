from django.db import models

# Create your models here.


class OLARideModel(models.Model):
    longitude = models.DecimalField(max_digits=9, decimal_places=6)
    latitude = models.DecimalField(max_digits=9, decimal_places=6)
    eta = models.DurationField(null=True)
    fare_details = models.TextField()

    def __str__(self):
        return '{} {}'.format(self.latitude, self.longitude)
