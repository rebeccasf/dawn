@group(1) @binding(0) var arg_0 : texture_depth_2d;

fn textureDimensions_939fdb() {
  var res : vec2<i32> = textureDimensions(arg_0);
}

@stage(vertex)
fn vertex_main() -> @builtin(position) vec4<f32> {
  textureDimensions_939fdb();
  return vec4<f32>();
}

@stage(fragment)
fn fragment_main() {
  textureDimensions_939fdb();
}

@stage(compute) @workgroup_size(1)
fn compute_main() {
  textureDimensions_939fdb();
}
