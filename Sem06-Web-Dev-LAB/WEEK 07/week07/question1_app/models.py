from django.db import models


class Category(models.Model):
    name = models.CharField(max_length=30)
    email = models.EmailField()

    visits = models.IntegerField()
    likes = models.IntegerField()

    def __str__(self):
        return "%s %s" % (self.name, self.email)


class Page(models.Model):
    category = models.ForeignKey(Category, on_delete=models.CASCADE)
    title = models.CharField(max_length=30)
    url = models.URLField()
    views = models.IntegerField()

    def __str__(self):
        return self.title

    class Meta:
        ordering = ['title']
