package emit

import (
	"os"
	"path/filepath"

	"github.com/mochilang/mochi-ruby/transpiler/ruby/rtree"
)

// Emit writes sf as a .rb file under workDir. Returns the absolute path of
// the written file.
func Emit(sf *rtree.SourceFile, workDir string) (string, error) {
	if err := os.MkdirAll(workDir, 0o755); err != nil {
		return "", err
	}
	path := filepath.Join(workDir, sf.Name+".rb")
	if err := os.WriteFile(path, []byte(sf.RubySource()), 0o644); err != nil {
		return "", err
	}
	return path, nil
}
