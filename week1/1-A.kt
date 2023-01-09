import java.util.*

fun main() {
    val scanner = Scanner(System.`in`)

    val dwarfs = Array(9) { scanner.nextLine().toInt() }.toList()
    val sum = dwarfs.sum()
    var result: List<Int>

    for (i in 0..8) {
        for ( j in 0 .. 8) {
            if (i == j) continue
            if (sum - (dwarfs[i] + dwarfs[j]) == 100) {
                result = dwarfs
                    .filterIndexed{ index, _ -> (index != i) && (index != j) }
                    .sorted()
                result.forEach { println(it) }
                return
            }
        }
    }
}