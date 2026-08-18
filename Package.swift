// swift-tools-version: 5.6
// The swift-tools-version declares the minimum version of Swift required to build this package.
// 模板文件：由 submit_cocoapods.sh 根据实际版本号生成 Package.swift，请勿直接修改生成的 Package.swift

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
            url: "https://github.com/libpag/pag-ios/releases/download/4.5.92/libpag_4.5.92_ios_arm64_x86_64.zip",
            checksum: "6dcb03baabc9a00beb99ef2b5f7e28396e52c685c640d3721a3e3f3548d3d4f7")
    ]
)
