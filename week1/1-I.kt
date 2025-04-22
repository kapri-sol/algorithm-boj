fun main() {
    val (n, m) = readln().split(" ").map { it.toInt() }
    val numToName = Array(n) { "" }
    val nameToNum = HashMap<String, Int>()

    repeat(n) { i ->
        val name = readln()
        numToName[i] = name
        nameToNum[name] = i + 1
    }

    repeat(m) {
        val q = readln()
        println(
            q.toIntOrNull()?.let { numToName[it - 1] } ?: nameToNum[q]
        )
    }
}