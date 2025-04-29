from django.urls import path
from . import views

urlpatterns = [
    path('members/', views.members, name='members'),  # This will respond at '/members/'
]
