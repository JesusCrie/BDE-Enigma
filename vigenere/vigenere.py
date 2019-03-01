import re


def _normalize_to_az(data: str):
    data = re.sub(r'[^a-zA-Z]', ' ', data)
    return _convert_26(data)


def _convert_26(data: str):
    data = data.upper()
    return [ord(c) - ord('A') for c in data]


def _convert_az(data: list):
    return ''.join([chr(c + ord('A')) for c in data])


def _convert_to_ord(data: str):
    return [ord(c) for c in data]


def _convert_from_ord(data: list):
    return ''.join([chr(c) for c in data])


def vig_encrypt_26(msg: str, key: str):
    msg = _normalize_to_az(msg)
    key = _convert_26(key)

    msg = _vig_encrypt_generic(msg, key, 26)
    return _convert_az(msg)


def vig_decrypt_26(msg, key):
    msg = _convert_26(msg)
    key = _convert_26(key)
    return _convert_az(_vig_decrypt_generic(msg, key, 26))


def vig_encrypt_ascii(msg: str, key: str):
    msg = _convert_to_ord(msg)
    key = _convert_to_ord(key)

    msg = _vig_encrypt_generic(msg, key, 0x7f)
    return _convert_from_ord(msg)


def vig_decrypt_ascii(msg: str, key: str):
    msg = _convert_to_ord(msg)
    key = _convert_to_ord(key)

    msg = _vig_decrypt_generic(msg, key, 0x7f)
    return _convert_from_ord(msg)


def _vig_encrypt_generic(msg: list, key: list, alphabet_len: int):
    for i, char in enumerate(msg):
        msg[i] = char + key[i % len(key)] % alphabet_len

    return msg


def _vig_decrypt_generic(msg: list, key: list, alphabet_len: int):
    for i, char in enumerate(msg):
        msg[i] = char - key[i % len(key)] % alphabet_len

    return msg


if __name__ == '__main__':
    txt = 'Hey I\'m a banana !'
    key = 'banana'
    print('txt: %s' % txt)
    print('key: %s' % key)
    print('-' * 15)

    ciphered = vig_encrypt_ascii(txt, key)
    print('ciphered: %s' % ciphered)
    print('ciphered: 0x%s' % ''.join([hex(ord(c))[2:] for c in ciphered]))
    deciphered = vig_decrypt_ascii(ciphered, key)
    print('deciphered: %s' % deciphered)
    print('deciphered: 0x%s' % ''.join([hex(ord(c))[2:] for c in deciphered]))
