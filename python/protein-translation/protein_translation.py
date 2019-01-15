from textwrap import wrap

def proteins(strand):
    dic_protein = {"AUG" : "Methionine",
                   "UUU" : "Phenylalanine",
                   "UUC" : "Phenylalanine",
                   "UUA" : "Leucine",
                   "UUG" : "Leucine",
                   "UCU" : "Serine",
                   "UCC" : "Serine",
                   "UCA" : "Serine",
                   "UCG" : "Serine",
                   "UAU" : "Tyrosine",
                   "UAC" : "Tyrosine",
                   "UGU" : "Cysteine",
                   "UGC" : "Cysteine",
                   "UGG" : "Tryptophan",
                   "UAA" : "STOP",
                   "UAG" : "STOP",
                   "UGA" : "STOP"}

    codon = wrap(strand, 3)
    protein = []

    for i in codon:
        if dic_protein[i] == "STOP":
            return protein
        else:
            protein.append(dic_protein[i])

    return protein
