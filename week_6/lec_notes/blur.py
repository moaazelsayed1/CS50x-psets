from PIL import Image, ImageFilter
before = image.open("moaz.jpg")
after = before.filter(ImageFilter.blur)