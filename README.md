# mochi-ruby

Mochi+Ruby bidirectional package bridge ([MEP-76](https://mochilang.org/docs/mep/mep-0076)).

Two directions:

- **Consume**: `import ruby "redis@~> 5.0" as redis` — use any RubyGem in Mochi without boilerplate.
- **Publish**: `mochi pkg publish --to=rubygems.org` — ship a Mochi package as a native gem with trusted OIDC publishing.

## Packages

| Package | Description |
|---------|-------------|
| `errors` | SkipReason sentinel values + BridgeError |
| `semver` | RubyGems-flavoured semver parser and constraint engine |
| `index` | RubyGems compact-index client (SHA-256 verified downloads, content-addressed cache) |
| `rbs` | RBS file parser, gem_rbs_collection fetcher, YARD fallback |
| `typemap` | Closed RBS-to-Mochi type translation table |
| `wrapper` | shim.rb + shim.mochi emitter |
| `build` | Bundler orchestration (Gemfile synthesis, bundle install, async bootstrap) |
| `gemspec` | gemspec renderer from mochi.toml `[ruby.publish]` |
| `publish` | Trusted OIDC publishing to rubygems.org |
| `nativeext` | Native C-extension gem detection and pure-Ruby fallback map |

## Requirements

- Go 1.22+
- Ruby 3.2+ with Bundler (for `build` package integration tests)

## Usage

```go
import "github.com/mochilang/mochi-ruby/index"

client := index.NewClient("")
versions, err := client.FetchVersions(ctx, "redis")
```

## CI

[![CI](https://github.com/mochilang/mochi-ruby/actions/workflows/ci.yml/badge.svg)](https://github.com/mochilang/mochi-ruby/actions/workflows/ci.yml)

## License

Same as the main Mochi repository.
