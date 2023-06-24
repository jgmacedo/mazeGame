import random

def generate_vectors(num_vectors):
    vectors = []
    used_values = set()

    for _ in range(num_vectors):
        i = random.randint(1, 30)
        k = random.randint(1, 30)
        vector = [i, k, 0]

        while tuple(vector) in used_values:
            i = random.randint(1, 30)
            k = random.randint(1, 30)
            vector = [i, k, 0]

        used_values.add(tuple(vector))
        vectors.append(vector)

    vectors.sort(key=lambda v: v[0])
    return vectors

num_vectors = 25
vectors = generate_vectors(num_vectors)

for vector in vectors:
    print(f"{{{vector[0]}, {vector[1]}, 0}}")
