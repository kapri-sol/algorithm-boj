fun main() {
    val input = readln()
    val alphabet = IntArray(26)

    for (char in input) {
        alphabet[char - 'a']++
    }

    println(alphabet.joinToString(" "))
}