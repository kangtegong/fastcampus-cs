import unicodedata

input_value = input("인코딩할 값을 입력하세요: ")

print("유니코드 코드 포인트:")
for char in input_value:
    code_point = ord(char)
    print(f"문자 '{char}': U+{code_point:04X}")

# UTF-8 인코딩
utf8_encoded = input_value.encode('utf-8')
print("UTF-8 인코딩 결과:", utf8_encoded)

# UTF-16 인코딩
utf16_encoded = input_value.encode('utf-16')
print("UTF-16 인코딩 결과:", utf16_encoded)

# UTF-32 인코딩
utf32_encoded = input_value.encode('utf-32')
print("UTF-32 인코딩 결과:", utf32_encoded)
