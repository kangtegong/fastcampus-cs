f_name = "example.txt"
fileObject = open(f_name, "r")

print("The file descriptor for %s is %s" % (f_name, fileObject.fileno()))

