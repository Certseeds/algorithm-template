# lab_06_F — Minimal Half Length (Substitution Cipher)

## Description

There is a string `S_0` with length `2m`.

Its first half `S_0[1,m]` is the substitution cipher of the second half `S_0[m+1,2m]`.

Then for some reason, the second half of `S_0` may lose some characters at the end, resulting in string `S`.

Given this string `S`, you need to answer the smallest possible value of `m`.

Hint: substitution cipher is an encryption method that replaces letters in the text with other letters.

For example, if our encryption rule is `a->c,b->a,c->b`, then the string "accb" will be encrypted into "cbba".

## Input

The first line is the code table for the substitution cipher, which contains 26 letters representing the encrypted letter for each letter in lexicographical order.

The second line is `S  (1<= |S| <= 5*10^5)`.

## Output

One integer, indicating the minimal possible length of the second half.

## Sample Input

```log
b c d e f g h i j k l m n o p q r s t u v w x y z a
bcdeabc
```

## Sample Output

```log
4
```

## HINT
