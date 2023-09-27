#!/usr/bin/python3

def qs(arr, l, h):
	if not (l < h):
		return
	j = l - 1
	i = l
	while i < h - 1:
		if arr[i] < arr[h - 1]:
			j += 1
			if i != j:
				arr[i], arr[j] = arr[j], arr[i]
				print(arr)
		i += 1
	j += 1
	if j != h - 1:
		arr[j], arr[h - 1] = arr[h - 1], arr[j]
		print(arr)
	qs(arr, l, j)
	qs(arr, j + 1, h)


def quick_sort(arr, size):
	if size < 2:
		return
	qs(arr, 0, size)


ls = [19, 48, 99, 71, 13, 52, 96, 73, 86, 7]
print(ls)
print()

quick_sort(ls, len(ls))

print()
print(ls)
