// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.
import PackageDescription

let package = Package(
    name: "ConvivaSDK",
    platforms: [
        .iOS(.v12),
        .tvOS(.v12)
    ],
    products: [
        // Products define the executables and libraries a package produces, and make them visible to other packages.
        .library(
            name: "ConvivaSDK",
            targets: ["ConvivaSDK"]),
    ],
    dependencies: [
        // Dependencies declare other packages that this package depends on.
        // .package(url: /* package url */, from: "1.0.0"),
    ],
    targets: [
        .binaryTarget(
            name: "ConvivaSDK",
            url: "https://github.com/Conviva/ConvivaSDK/raw/4.0.43/Framework/ConvivaSDK.xcframework.zip",
            checksum: "a62100f18feaacb6ea6bbf99d9a50ecf87ed60d605de304bce743d13e2e0cbe0")
    ]
)
