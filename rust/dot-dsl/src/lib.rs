pub mod graph {
    use graph_items::edge::Edge;
    use graph_items::node::Node;
    use std::collections::HashMap;

    pub struct Graph {
        pub edges: Vec<Edge>,
        pub nodes: Vec<Node>,
        pub attrs: HashMap<String, String>,
    }

    impl Graph {
        pub fn new() -> Self {
            return Graph {
                edges: Vec::new(),
                nodes: Vec::new(),
                attrs: HashMap::new(),
            };
        }

        pub fn with_edges(mut self, edges: &[Edge]) -> Self {
            self.edges = Vec::from(edges);
            return self;
        }

        pub fn with_nodes(mut self, nodes: &[Node]) -> Self {
            self.nodes = Vec::from(nodes);
            return self;
        }

        pub fn with_attrs(mut self, attrs: &[(&str, &str)]) -> Self {
            for (key, val) in attrs.iter().copied() {
                self.attrs.insert(key.parse().unwrap(), val.parse().unwrap());
            }
            return self;
        }

        pub fn get_node(&self, label: &str) -> Option<&Node> {
            return self.nodes.iter().find(|&node| node.label == label);
        }
    }

    pub mod graph_items {
        pub mod edge {
            use std::collections::HashMap;

            #[derive(Clone, PartialEq, Debug)]
            pub struct Edge {
                pub from: String,
                pub to: String,
                attrs: HashMap<String, String>,
            }

            impl Edge {
                pub fn new(from: &str, to: &str) -> Self {
                    Edge {
                        from: from.to_owned(),
                        to: to.to_owned(),
                        attrs: HashMap::new(),
                    }
                }

                pub fn with_attrs(mut self, attrs: &[(&str, &str)]) -> Self {
                    for (key, val) in attrs.iter().copied() {
                        self.attrs.insert(key.parse().unwrap(), val.parse().unwrap());
                    }
                    return self;
                }
            }
        }

        pub mod node {
            use std::collections::HashMap;

            #[derive(Clone, PartialEq, Debug)]
            pub struct Node {
                pub label: String,
                pub attrs: HashMap<String, String>,
            }

            impl Node {
                pub fn new(label: &str) -> Self {
                    return Node {
                        label: label.to_owned(),
                        attrs: HashMap::new(),
                    };
                }

                pub fn with_attrs(mut self, attrs: &[(&str, &str)]) -> Self {
                    for (key, val) in attrs.iter().copied() {
                        self.attrs.insert(key.parse().unwrap(), val.parse().unwrap());
                    }
                    return self;
                }

                pub fn get_attr(&self, attr: &str) -> Option<&str> {
                    self.attrs.get(attr).map(String::as_ref)
                }
            }
        }
    }
}
