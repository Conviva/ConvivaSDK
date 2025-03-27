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
            url: "https://github.com/Conviva/ConvivaSDK/raw/4.1.2/Framework/ConvivaSDK.xcframework.zip",
            checksum: "f4f93c1f44d4e662c7b22ce0b95184cf3b910e523e368a208271909ce970f2be"),
linkerSettings: [
                .linkedFramework("CoreMedia", .when(platforms: [.iOS,.tvOS])),
                .linkedFramework("SystemConfiguration", .when(platforms: [.iOS,.tvOS])),
		.linkedFramework("MobileCoreServices", .when(platforms: [.iOS,.tvOS])),
                .linkedFramework("CoreTelephony", .when(platforms: [.iOS])),
		.linkedFramework("Network", .when(platforms: [.iOS,.tvOS])),
		.linkedFramework("AVFoundation", .when(platforms: [.iOS,.tvOS])),
		.linkedFramework("AppTrackingTransparency", .when(platforms: [.iOS,.tvOS])),
                .unsafeFlags(["-ObjC"], .when(platforms: [.iOS,.tvOS])),
            ]
    ]
)
