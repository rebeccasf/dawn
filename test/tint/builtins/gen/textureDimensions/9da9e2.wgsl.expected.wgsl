@group(1) @binding(0) var arg_0 : texture_storage_1d<rgba8sint, write>;

fn textureDimensions_9da9e2() {
  var res : i32 = textureDimensions(arg_0);
}

@stage(vertex)
fn vertex_main() -> @builtin(position) vec4<f32> {
  textureDimensions_9da9e2();
  return vec4<f32>();
}

@stage(fragment)
fn fragment_main() {
  textureDimensions_9da9e2();
}

@stage(compute) @workgroup_size(1)
fn compute_main() {
  textureDimensions_9da9e2();
}
