import threading

def foo():
    print("foo executed")

def bar():
    print("bar executed")

def baz():
    print("baz executed")

if __name__ == "__main__":
    thread1 = threading.Thread(target=foo)
    thread2 = threading.Thread(target=bar)
    thread3 = threading.Thread(target=baz)

    thread1.start()
    thread2.start()
    thread3.start()

    thread1.join()
    thread2.join()
    thread3.join()

