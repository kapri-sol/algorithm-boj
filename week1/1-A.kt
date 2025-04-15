fun main() {
    val heights = List(9) { readln().toInt() }
    val sum = heights.sum()

    for (i in 0 until 9) {
        for (j in i + 1 until 9) {
            if ((sum - heights[i] - heights[j]) == 100) {
                heights
                    .filterIndexed { idx, _ -> idx != i && idx != j }
                    .sorted()
                    .forEach { println(it) }
                return
            }
        }
    }
}