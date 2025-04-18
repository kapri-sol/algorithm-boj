fun rot13(char: Char): Char = when (char) {
    in 'a'..'z' -> 'a' + (char - 'a' + 13) % 26
    in 'A'..'Z' -> 'A' + (char - 'A' + 13) % 26
    else -> char
}

fun main() {
    val str = readln()
    val result = str.map { rot13(it) }.joinToString("")
    println(result)
}