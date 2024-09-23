import java.util.*

fun main() {
    val scanner = Scanner(System.`in`)
    val N = scanner.nextInt()
    val dp = IntArray(10000001) { 0 }

    for (i in 2..N) {
        dp[i] = dp[i - 1] + 1
        if (i % 2 == 0) {
            dp[i] = minOf(dp[i], dp[i / 2] + 1)
        }
        if (i % 3 == 0) {
            dp[i] = minOf(dp[i], dp[i / 3] + 1)
        }
    }
    println(dp[N])
}
