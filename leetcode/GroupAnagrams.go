// https://leetcode.com/problems/group-anagrams/

package main

import (
	"sort"
	"strings"
)

func groupAnagrams(strs []string) [][]string {
	dict := make(map[string][]string)

	for _, v := range strs {
		string_split := strings.Split(v, "")
		sort.Strings(string_split)
		string_key := strings.Join(string_split, "")
		//fmt.Println(string_key)
		if dict_v, ok := dict[string_key]; ok {
			dict[string_key] = append(dict_v, v)
		} else {
			dict[string_key] = []string{v}
		}
	}
	result := make([][]string, 0, len(dict))

	for _, value := range dict {
		result = append(result, value)
	}

	return result

}

func main() {
	strs := []string{"eat", "tea", "tan", "ate", "nat", "bat"}
	groupAnagrams(strs)
}
