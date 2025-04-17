fun main() {
    val alphabets = IntArray(26)

    repeat(readln().toInt()) {
        alphabets[readln()[0] - 'a']++
    }

    val result = buildString {
        alphabets.forEachIndexed { i, count ->
            if (count >= 5) append('a' + i)
        }
    }

    println(result.ifEmpty { "PREDAJA" })
}