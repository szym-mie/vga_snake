import sys
from textwrap import indent

def rgb222(r, g, b):
    """
    convert 24-bit decomposed RGB pixel value to packed RGB222 format
    :param r: red channel
    :param g: green channel
    :param b: blue channel
    """
    rc = int(r) // 64
    gc = int(g) // 64
    bc = int(b) // 64

    return (rc << 4) | (gc << 2) | (bc << 0)


def c_tile(tile_name, im_fp):
    pformat = im_fp.readline()
    if 'P3' not in pformat:
        raise RuntimeError('pixmap is of {} - should use P3'.format(pformat))
    im_fp.readline() # skip GIMP comment
    x, y = [int(n) for n in im_fp.readline().split(' ')] # read image size
    remain = x * y

    im_fp.readline() # skip max color value 
    
    yield '{{ /* {} ({}x{}) */'.format(tile_name.upper(), x, y)
    for _ in range(y):
        line = ''
        for _ in range(x):
            r = int(im_fp.readline())
            g = int(im_fp.readline())
            b = int(im_fp.readline())
            remain -= 1

            sep = ',' if remain > 0 else ''
            line += '0x{:02x}{} '.format(rgb222(r, g, b), sep) 
        yield indent(line, '    ')
    yield '}'


if __name__ == '__main__':
    try:
        argc = len(sys.argv)
        if argc != 3:
            if argc < 3:
                print('missing arguments')
            else:
                print('too much arguments')
            print('python ppm_to_rgb222.py TILE_NAME PPM_PATH')
            print('  TILE_NAME - internal name for future reference in C code')
            print('  PPM_PATH - path to PPM pixmap in P3 format')
        tile_name = sys.argv[1]
        im_name = sys.argv[2]
        with open(im_name, 'r') as im_fp:
            print('\n'.join(c_tile(tile_name, im_fp)))
    except RuntimeError as e:
        print('error: {}'.format(e))

