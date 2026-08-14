// swift-tools-version: 5.6
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "libpag",
    platforms: [.iOS(.v9)],
    products: [
        .library(
            name: "libpag",
            targets: ["libpag"]),
    ],
    targets: [
        .binaryTarget(
            name: "libpag",
            url: "https://github.com/libpag/pag-ios/releases/download/4.3.76/libpag_4.3.76_ios_arm64_x86_64.zip",
            checksum: "42d89fde7dba5b5634720f7aef3fac17f6569e287f0b8aa012d675797310a35d")
    ]
)
